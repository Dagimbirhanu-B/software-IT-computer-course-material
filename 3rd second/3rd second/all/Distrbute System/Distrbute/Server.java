import java.util.*;
import java.net.*;
import java.io.*;

public class Server{
  public static void main(String[] args) throws IOException{
    ServerSocket ss=new ServerSocket(8233);
    System.out.println("Wait the client request");

    Socket sk=ss.accept();
    System.out.println("Connection Establishd");
    
    BufferedReader br=new BufferedReader(new InputStreamReader(sk.getInputStream()));
    String s=br.readLine();
    System.out.println("Message from client "+s);
    br.close();
    ss.close();

  }
}
