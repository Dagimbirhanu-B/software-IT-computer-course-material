import java.util.*;
import java.net.*;
import java.io.*;


public class Client{
  public static void main(String[] args){
    try{
      Socket sk=new Socket("localhost",8233);
      PrintWriter pw=new PrintWriter(sk.getOutputStream());
      pw.println("Hello Server how are u? ");
      pw.close();
      sk.close();
    }catch(Exception e){
      System.out.println(e);
    }
  }
}
