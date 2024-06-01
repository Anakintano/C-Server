#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024] = {0};

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Set server address information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY; // Connect to localhost

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char *hello = "Hello from client";
    send(sockfd, hello, strlen(hello), 0);
    printf("Client: Sent message: %s\n", hello);

    // Receive a response from the server
    int recv_size = recv(sockfd, buffer, sizeof(buffer), 0);
    if (recv_size == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("Client: Received response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}

