## README: Simple C Server and Client

This document explains how to set up, compile, and run a basic C server-client application for communication. This code demonstrates TCP socket programming for sending and receiving messages.

**Functionality:**

- The server listens for connections on a specified port (default: 8080).
- The client connects to the server and sends a message.
- The server receives the message and sends a response back to the client.

**Requirements:**

- C compiler (GCC for Linux/Mac, Visual Studio or MinGW for Windows)
- Basic understanding of C programming and the command line

**Instructions:**

**1. Copying the Code:**

* **Linux/Mac:**
    - Open a terminal window.
    - Use the `cp` command to copy the code files to a suitable directory:

    ```bash
    cp server.c client.c /path/to/your/directory/
    ```

    Replace `/path/to/your/directory/` with the actual directory where you want to store the files.
* **Windows:**
    - Use file explorer to navigate to the directory where you want to store the code files.
    - Right-click, select "New" -> "Text Document".
    - Paste the server code into one file and save it as "server.c".
    - Repeat for the client code, saving it as "client.c".

**2. Compiling the Code:**

* **Linux/Mac:**

    - Open a terminal window and navigate to the directory where you copied the code files.
    - Compile the server code using GCC:

    ```bash
    gcc server.c -o server -lnet
    ```

    This creates an executable file named "server". The `-lnet` flag links the program with the network library.
    - Compile the client code similarly:

    ```bash
    gcc client.c -o client -lnet
    ```

    This creates an executable file named "client".

* **Windows:**

    **Using Command Prompt:**

    - Open a command prompt window and navigate to the directory where you saved the code files.
    - Compile the server code using GCC (assuming you have MinGW installed):

    ```batch
    g++ server.c -o server -lws2_32
    ```

    This creates an executable file named "server". The `-lws2_32` flag links the program with the Windows sockets library.
    - Compile the client code similarly:

    ```batch
    g++ client.c -o client -lws2_32
    ```

    **Using an IDE (Integrated Development Environment):**

    - If you have an IDE like Visual Studio, create a new C project and add the "server.c" and "client.c" files to it.
    - Configure the project settings to link with the appropriate networking libraries (e.g., `ws2_32.lib` for Windows).
    - Build the project to create the executable files.

**3. Running the Server:**

- Open a terminal window (Linux/Mac) or command prompt (Windows).
- Navigate to the directory where the compiled server executable ("server") is located.
- Run the server:

    ```bash
    ./server  // Linux/Mac
    server.exe // Windows
    ```

    This starts the server, listening for connections on port 8080 (default).

**4. Running the Client:**

- In a separate terminal/command prompt window, navigate to the directory where the compiled client executable ("client") is located.
- **Localhost Method:**
    - Run the client:

    ```bash
    ./client  // Linux/Mac
    client.exe // Windows
    ```

    This connects the client to the server running on the same machine (localhost) at port 8080 by default. You should see the message exchange between the client and server in the terminal windows.

**Additional Notes:**

- You can modify the port number in the code (both server and client) if needed.
- Make sure there are no firewalls blocking connections on port 8080.
- This is a basic example. Real-world applications would typically involve more robust error handling and communication protocols.

**Troubleshooting:**

- If you encounter errors during compilation or execution, check for typos in the code and ensure you have the necessary libraries installed.
- Use debugging tools (like `gdb` on Linux/Mac or built-in debuggers in IDEs) to step through the code and identify issues.

I hope this detailed README helps you set up and run the C server-client application!
