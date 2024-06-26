#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer = {0};
  char *hello = "Hello from server";


  //SOCKET creation
 if(( server_fd = socket(AF_INET , SOCK_STREAM , 0)) < 0 ) {
     perror("socket failed");
    exit(EXIT_FAILURE);
  }

 // SOCKET bind
 if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
 }


 // SOCKET listen 
if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // 4. Accept
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }
} 
