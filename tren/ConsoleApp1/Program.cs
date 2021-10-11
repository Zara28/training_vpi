using System;
using System.IO;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 202;
            bool verno;
            int sum = 0;
            List<string> pon = new List<string>();
            List<string> opr = new List<string>();
            string path_hist = "hist.txt";
            string path_fil = "fil.txt";
            string path_eng = "eng.txt";
            Console.WriteLine("Привет, это твой тренажер\n\n");
            while (n != 101)
            {
                pon.Clear();
                opr.Clear();
                int ccount = 0;
                Console.WriteLine("Введи номер предмета, по которому хочешь тренироваться\n 1.История\n 2.Философия\n 3.Английский \n для закрытия программы введи 101\n Для перевыбора предмета введи 100");
                n = Convert.ToInt32(Console.ReadLine());
                string path = "";
                switch(n)
                {
                    case 1:
                        path = path_hist;
                        break;
                    case 2:
                        path = path_fil;
                        break;
                    case 3:
                        path = path_eng;
                        break;
                    case 101:
                        continue;
                }

                try
                {
                    using (StreamReader sr = new StreamReader(path))
                    {
                        for (int i = 0; i < 50; i++)
                        {
                            string s = sr.ReadLine();
                            pon.Add(s.Split(";")[0]);
                            opr.Add(s.Split(";")[1].ToLower());

                        }

                    }
                }
               catch
                {
                    if (n!=100)
                    {

                        Console.WriteLine("Произошла ошибка. Выберите снова");
                    }
                    else
                    {
                        Console.WriteLine("Вы еще не выбрали");
                    }

                    continue;
                }
                while (n!=100)
                {
                    Random rand = new Random();
                    int r = rand.Next(0, 49);
                    Console.WriteLine(opr[r]);
                    string ans = Console.ReadLine().ToLower();
                    if (ans == pon[r])
                    {
                        ccount += 1;
                    }
                    else if (ans == "100")
                    {
                        n = 100;
                        Console.WriteLine("Ваш счет: " + Convert.ToString(ccount));
                        Console.Clear();
                        continue;
                    }
                    else if (ans == "101"){
                        n = 101;
                        Console.WriteLine("Ваш счет: " + Convert.ToString(ccount));
                        break;
                    }
                    sum += ccount;

                    Console.WriteLine("Ваш общий счет: " + Convert.ToString(ccount));
                    Console.Clear();
                }

            }

            Console.WriteLine("Ваш общий счет: " + Convert.ToString(sum));
        }

    }
}
