import java.io.*;
import java.net.*;
public class ClientClass{
  public static void main(String[] args){
    try{
      Socket sk=new Socket("10.129.172.117",1234);
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw=new PrintWriter(sk.getOutputStream(),true);
      BufferedReader input=new BufferedReader(new InputStreamReader(sk.getInputStream()));
      String send="",recieve="";
      while(true){
        send=br.readLine();
        pw.println(send);
        if((recieve=input.readLine())!=null){
          System.out.println("Server:"+recieve);
        }
        if(send.equalsIgnoreCase("bye")){
          System.exit(0);

        }
      }
    }catch(Exception e){
      System.out.println(e.getMessage());
    }
  }
}
