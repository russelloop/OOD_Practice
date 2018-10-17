using System;

namespace test{
    class MainClass{
        public static void Main(string[] args){
            //Q1
            Console.WriteLine("------------------ Q1 ------------------");
            int sum = 0;
            int m = 1;
            for (int i = 1; i <= 5; i++){
                m = m * i;
                sum += m;
            }
            Console.WriteLine("1! + 2! + 3! + 4! + 5! = " + sum);

            //Q2
            Console.WriteLine("------------------ Q2 ------------------");
            int multi_result = 0;
            for (int p = 1; p <= 9; p++){
                for (int q = 1; q <= p; q++){
                    multi_result = p * q;
                    Console.Write(p + "*" + q + " = " + multi_result + "  ");
                }
                Console.WriteLine("");
            }

            //Q3
            Console.WriteLine("------------------ Q3 ------------------");
            int[] num;
            num = new int[10];
            int read_num;
            for (int i = 0; i < num.Length; i++){
                read_num = Convert.ToInt32(Console.ReadLine());
                num[i] = read_num;
            }
            int[] max = getMax(num);
            Console.Write("Descending Output will be: ");
            for (int i = 0; i < max.Length; i++)
                Console.Write(max[i] + " ");

            //Q4
            Console.WriteLine("------------------ Q4 ------------------");
            double divisor, dividend;
            double quotient = 0;
            Console.Write("Please enter the dividend: ");
            dividend = Convert.ToDouble(Console.ReadLine());
            Console.Write("Now enter the divisor(number other than zero): ");
            divisor = Convert.ToDouble(Console.ReadLine());
            try{
                quotient = dividend / divisor;
            }
            catch(DivideByZeroException e){
                Console.WriteLine("Exception caught: {0}", e);
            }
            finally{
                Console.WriteLine(dividend + "/" + divisor + "=" + quotient);
            }

            //Q5
            Console.WriteLine("------------------ Q5 ------------------");
            Car myCar = new Car(300, 204);
            sportsCar mySportCar = new sportsCar(400, 399, "red");
            myCar.Speak();
            mySportCar.Speak();

            //Q6
            Console.WriteLine("------------------ Q6 ------------------");
            Feeder feeder = new Feeder();
            Pigeon pigeon = new Pigeon();
            Monkey monkey = new Monkey();
            Lion lion = new Lion();
            feeder.feed(pigeon);
            feeder.feed(monkey);
            feeder.feed(lion);
        }

        static int[] getMax(params int[] num){
            int temp;
            for (int i = 0; i < num.Length; i++)
                for (int j = i + 1; j < num.Length; j++)
                    if(num[i] < num[j]){
                        temp = num[i];
                        num[i] = num[j];
                        num[j] = temp;
                    }
            return num;
        }
    }

    class Car{
        protected int weight;
        protected int speed;
        public Car(int weight, int speed){
            this.weight = weight;
            this.speed = speed;
        }
        public virtual void Speak(){
            Console.WriteLine("A " + weight + "kg Car with the top speed over " + speed);
        }
    }

    class sportsCar: Car{
        private string color;
        public sportsCar(int weight, int speed, string color):base(weight, speed){
            this.color = color;
        }

        public override void Speak(){
            Console.WriteLine("A " + color + "Car " + "weight " + weight + "kg with the top speed over " + speed);
        }
    }

    abstract class Animal{
        public abstract void eat();
    }

    class Lion: Animal{
        public override void eat(){
            Console.WriteLine("Lion eat meats.");
        }
    }
     
    class Monkey: Animal{
        public override void eat(){
            Console.WriteLine("Monkey eat bananas.");
        }
    }

    class Pigeon: Animal{
        public override void eat(){
            Console.WriteLine("Pigeon eat corn.");
        }
    }

    class Feeder{
        public void feed(Animal ani){
            ani.eat();
        }
    }
}
