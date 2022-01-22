using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Number_of_Students_Unable_to_Eat_Lunch
    {
        public int CountStudents(int[] students, int[] sandwiches)
        {
            Queue<int> stud = new Queue<int>();
            Stack<int> sand = new Stack<int>();

            for (int i = 0; i < students.Length; i++)
                stud.Enqueue(students[i]);

            for (int i = sandwiches.Length - 1; i >= 0; i--)
                sand.Push(sandwiches[i]);

            for (int i = 0; i <= stud.Count; i++)
            {
                if (stud.Peek() == sand.Peek())
                {
                    stud.Dequeue();
                    sand.Pop();
                    i = 0;
                }

                else
                    stud.Enqueue(stud.Dequeue());
            }

            return stud.Count;
        }
    }
}
