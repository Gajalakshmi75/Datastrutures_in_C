import java.util.Random;
public class JavaRandomEaxmple{
    public static void main(String[] args){
        //Create Random Object
Random random= new Random();
//Returns Unlimited stream of pseudorandom long values
boolean val= random.nextBoolean();
System.out.println("Randowm Bollean Value;"+val);
byte[] bytes= new byte[10];
//generates random bytes and put them in array
random.nextBytes(bytes);
System.out.println("Random Bytes=(");
for (int i=0; i<bytes.length; i++)
{
    System.out.println("%d",bytes[i]);
}
System.out.println(")");
}
}