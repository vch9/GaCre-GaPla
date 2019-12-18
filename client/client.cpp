#include <stdio.h>
#include <stdlib.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>

#define DATA_SIZE 1024
#define PORT 8080

using namespace std;
#include <iostream>
#include <fstream>

bool file_exist(string path);

void send(int s, char* msg, int len){
  if(send(s, msg, len, 0) == -1){
  }
}

void save_file(bool board, char* buf){
  /* Save .game or .board in ../games or ../boards */
  int len = buf[1];
  int len_name = buf[2];

  /* Copy name */
  char name[64];
  memset(name, 0, 64);
  for(int i=0; i<len_name; i++){
    name[i] = buf[3+i];
  }

  string prefix = "../games/";
  if(board)
    prefix = "../boards/";

  string name_str = std::string(name);
  if(file_exist(prefix+name_str)){
    cout << prefix+name_str << " already exist ! " << endl;
  } else {
    string str = "";
    for(int i=3+len_name; i<len; i++){
      str += buf[i];
    }
    
    ofstream outfile;
    outfile.open(prefix+name_str);
    outfile << str << endl;          
    outfile.close();
    
    if(!board)
      cout << "File saved: ../games/" << name_str  << endl;
    else      
      cout << "File saved: ../boards/" << name_str  << endl;
  }
}

void send_request_board_game(bool board, int s, char* name){
  char* msg = (char*)malloc(sizeof(char)*(strlen(name)+3));
  memset(msg, 0, strlen(name)+3);

  if (board)
    msg[0] = 7;
  else
    msg[0] = 8;

  msg[1] = 1+strlen(name);
  msg[2] = strlen(name);
  for(int i=0; i<(int)strlen(name); i++)
    msg[i+3] = name[i];

  send(s, msg, msg[1]+2);
  free(msg);
}

void send_request_list(bool board, int s){
  char* msg = (char*)malloc(sizeof(char)*2);
  if(board)
    msg[0] = 5;
  else
    msg[0] = 6;
  msg[1] = 0;

  send(s, msg, 2);
  free(msg);
}

void disconnect(int s){
  char* msg = (char*)malloc(sizeof(char)*2);
  msg[0] = 0;
  msg[1] = 0;

  send(s, msg, 2);
  
  free(msg);
}

bool file_exist(string path){
  if(FILE* file = fopen(path.c_str(), "r")){
    fclose(file);
    return true;
  }
  return false;
}

void send_board_game(bool board, int s, string file){
  string path;
  if(board)
    path = "../boards/"+file;
  else
    path = "../games/"+file;
  
  if(!file_exist(path)){
    cout << "There is no such " << path << endl;
    return;
  }

  char* msg = (char*)malloc(sizeof(char)*DATA_SIZE);
  memset(msg, 0, DATA_SIZE);

  if(board)
    msg[0] = 3;
  else
    msg[0] = 4;
  
  int len = 1;

  msg[2] = file.size();
  for(int i=0; i<(int)file.size(); i++){
    msg[3+i] = file[i];
    len++;
  }
  ifstream is(path);
  char c;

  int k = 2 + file.size() + 1;
  while(is.get(c)){
    msg[k] = c;
    k++;
    len++;
  }
  msg[k] = c;
  len++;

  msg[1] = len;
  is.close();

  send(s, msg, len+2);
  free(msg);
}

int main(int argc, char* argv[]){
  int s, rc;

  if(argc<3){
    printf("Invalid ./client args \n");
    exit(1);
  }

  s = socket(AF_INET, SOCK_STREAM, 0);
  if(s==-1){
    printf("Socket creation failed\n");
    exit(1);
  }

  struct sockaddr_in serv;
  memset(&serv, 0, sizeof(serv));

  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv.sin_port = htons(PORT);

  rc = connect(s, (sockaddr*)&serv, sizeof(serv));
  if (rc != 0){
    printf("Connection with the server failed\n");
    exit(1);
  }

  
  if(strncmp("-send", argv[1], sizeof("-send"))==0){
    if(strncmp("-game", argv[2], sizeof("-game"))==0){
      send_board_game(false, s, std::string(argv[3]));
    }
    if(strncmp("-board", argv[2], sizeof("-board"))==0){
      send_board_game(true, s, std::string(argv[3]));
    }
  }

  if(strncmp("-list", argv[1], sizeof("-list"))==0){
    if(strncmp("-game", argv[2], sizeof("-game"))==0){
      send_request_list(false, s);
    }
    if(strncmp("-board", argv[2], sizeof("-board"))==0){
      send_request_list(true, s);
    }
  }

  if(strncmp("-request", argv[1], sizeof("-request"))==0){
    if(strncmp("-game", argv[2], sizeof("-game"))==0){
      send_request_board_game(false, s, argv[3]);
    }
    if(strncmp("-board", argv[2], sizeof("-board"))==0){
      send_request_board_game(true, s, argv[3]);
    }
  }

  char buf[DATA_SIZE];
  int n;
  while(1){
    memset(buf, 0, DATA_SIZE);
    n = recv(s, buf, DATA_SIZE, 0);
    if(n==0){
      break;
    }

    if(buf[0]==0){
      /* Transmission over */
      break;
    }
    
    if(buf[0]==42){
      /* Display type */
      int len = buf[1];
      for(int i=2; i<2+len; i++){
        printf("%c", buf[i]);
      }
      printf("\n");
    }

    if(buf[0] == 9 || buf[0] == 10){
      char* msg = (char*)malloc(sizeof(char)*sizeof(buf));
      memset(msg, 0, sizeof(buf));
      memcpy(msg, buf, sizeof(buf));

      if(buf[0] == 9)
        save_file(true, msg);
      else
        save_file(false, msg);
    }
  }

  close(s);
  printf("Communication is over\n");
}
