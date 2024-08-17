import java.net.*;
import java.io.*;
import java.net.*;
import java.util.*;

public class ServerClass{
  public static void main(String[] args) throws IOException{
    InetAddress host=InetAddress.getLocalHost();
    ServerSocket ss=new ServerSocket(6090);
    System.out.println("Server is Waiting to Connect");
    Socket sk=ss.accept();
    System.out.println("Connection establishd");
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw= new PrintWriter(sk.getOutputStream(),true);
    BufferedReader input=new BufferedReader(new InputStreamReader(sk.getInputStream()));
    String send="",recieve="";
    while(true){
      if((recieve=input.readLine())!=null){
        Date d=new Date();
        System.out.println("Client:"+recieve);

        System.out.println("Host="+host+d.toString());
      }
      send=br.readLine();
      pw.println(send);
      if(send.equalsIgnoreCase("bye")){
        System.exit(0);
      }
    }}}
