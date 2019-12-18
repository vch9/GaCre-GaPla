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

using namespace std;
#include <iostream>
#include <fstream>

#define DATA_SIZE 1024

bool game_already_exist(string pre, string f){
  f = pre+f;
  if(FILE* file = fopen(f.c_str(), "r")){
    fclose(file);
    return true;
  }
  return false;
}

void receive_board_game(int s, char* buf){
   /* Client offers a .game or .board */
  bool board = true;
  if (buf[0]==4)
    board = false;
  
  int len = buf[1];
  int len_name = buf[2];
  
  /* Copy name  */
  char name[64];
  memset(name, 0, 64);
  for(int i=0; i<len_name; i++){
    name[i] = buf[3+i];
  }

  string prefix = "./games/";
  if(board)
    prefix = "./boards/";

  string name_str = std::string(name);
  if(game_already_exist(prefix, name_str)){
    /* Respond that the name is taken */        
  } else {
    /* Store in games/ */
    string str = "";
    for(int i=3+len_name; i<len; i++){
      str += buf[i];
    }
    
    ofstream outfile;
    outfile.open(prefix+name_str);
    outfile << str << endl;          
    outfile.close();
    
    if(!board)
      cout << "File saved: ./games/" << name_str  << endl;
    else      
      cout << "File saved: ./boards/" << name_str  << endl;
  }
}

int receive_message(int s){
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  int fd;
  
  char buf[DATA_SIZE];
  int n;

  while(1){
    fd = accept(s, (sockaddr*)&client, &len);

    while(1){
      memset(buf, 0, DATA_SIZE);
      n = recv(fd, buf, DATA_SIZE, 0);

      if(n==0){
        printf("Connection closed\n");
        break;
      }
      
      if(buf[0]==0){
        /* Transmission is over */
        printf("Transmission is over\n");
        break;
      }
      if(buf[0]==1){
        /* Client request list of .game */      
      }
      if(buf[0]==2){
        /* Client request a specific game */
      }
      if(buf[0] == 3 || buf[0] == 4){
        /* Client offers a .board or .game */
        char* msg = (char*)malloc(sizeof(char)*sizeof(buf));
        memset(msg, 0, sizeof(buf));
        memcpy(msg, buf, sizeof(buf));
        receive_board_game(s, msg);
        free(msg);
      }
    }
  }
}

int main(){
  int rc, s;

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == -1){
    printf("Socket creation failed\n");
    exit(1);
  }

  struct sockaddr_in serv;
  memset(&serv, 0, sizeof(serv));

  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = htonl(INADDR_ANY);
  serv.sin_port = htons(8080);

  rc = bind(s, (sockaddr*)&serv, sizeof(serv));
  if (rc != 0){
    printf("Socket bind failed\n");
    exit(1);
  }

  rc = listen(s, 1024);

  if (rc != 0){
    printf("Listen failed\n");
    exit(1);
  }


  receive_message(s);

  close(s);
}
