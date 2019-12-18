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

void send(int s, char* msg, int len){
  if(send(s, msg, len, 0) == -1){
  }
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
  }

  close(s);
  printf("Communication is over\n");
}
