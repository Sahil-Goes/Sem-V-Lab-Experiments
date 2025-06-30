import java.io.*;
import java.net.*;

public class MyClient {
    public static void main(String[] args) {
        //To run this code to simulate chat on 2 different machines
        //ONLY Change "localhost" --> Use actual server IP
        //Ex: Socket socket = new Socket("192.168.1.100", 12345);   

        try (Socket socket = new Socket("localhost", 12345)) {
            System.out.println("Connected to the server!");

            BufferedReader inputFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter outputToServer = new PrintWriter(socket.getOutputStream(), true);

            BufferedReader clientInput = new BufferedReader(new InputStreamReader(System.in));

            String serverMessage, clientMessage;

            while (true) {
                System.out.print("Client: ");
                clientMessage = clientInput.readLine();
                outputToServer.println(clientMessage);

                if (clientMessage.equalsIgnoreCase("bye")) {
                    System.out.println("Disconnected from server.");
                    break;
                }

                serverMessage = inputFromServer.readLine();
                System.out.println("Server: " + serverMessage);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}