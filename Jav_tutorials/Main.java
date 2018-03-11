import java.util.Scanner; ///zaladuj Scanner - do pobierania z klaw. od usera
public class Main{
	public static void main(String args[]){
            /**System.out.println("Hello java programmer!");
            double x, y;
            x = 55.123;
            y = x + x;
            System.out.println(x);
            System.out.print(y); /// moze byc w albo jakw C++ x+x
            ///scanner - get data from user keyboard input
            Scanner slawek = new Scanner(System.in); ///zmienna scanner pobiera info
            System.out.println(slawek.nextLine()); ///.nextLine(); pauza i czekanie na input ze skanera
            */

        Scanner newVar = new Scanner(System.in);
        double fnum, snum, answer;
        System.out.println("Enter 1st number: ");
        fnum = newVar.nextDouble(); /// each data type ma swoja metode double, int, float etc ...
        System.out.println("Enter 2nd number: ");
        snum = newVar.nextDouble();
        answer = fnum + snum;
        System.out.println(answer);
        ///increment operators
        int vv2 = 5;
        int vv3 = 18;
        ++vv2; ///przedrostkowa
        System.out.println(++vv2);
        --vv3;
        System.out.println(--vv3);
        vv3 += 500; ///assignment operator
        System.out.println(vv3);
        ///conditions
        int test = 6;
        if (test == 9){
            System.out.println("True");
        }
        else{
            System.out.println("Bollocks it's NOT");
        }
        /// logical operators && and, || or
        /// switch(case)
        int counter=0;
        while(counter < 10){
            System.out.println(counter);
            counter++;
        }
    }
}



