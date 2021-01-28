using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tower_Of_Hanoi
{
    class StockSpanProblem
    {
        public static void Main(String[] args)
        {
            int[] price = { 100, 80, 60, 70, 60, 75, 85 };
            int n = price.Length;
            int[] S = new int[n];

            // Fill the span values in array S[] 
            calculateSpan(price, n, S);

            // print the calculated span values 
            printArray(S);
        }
        static void calculateSpan(int[] price, int n, int[] S)
        {
            // Create a stack and Push 
            // index of first element to it 
            Stack<int> st = new Stack<int>();
            st.Push(0);

            // Span value of first 
            // element is always 1 
            S[0] = 1;

            // Calculate span values 
            // for rest of the elements 
            for (int i = 1; i < n; i++)
            {

                // Pop elements from stack 
                // while stack is not empty 
                // and top of stack is smaller 
                // than price[i] 
                while (st.Count > 0 && price[(int)st.Peek()] <= price[i])
                    st.Pop();

                // If stack becomes empty, then price[i] is 
                // greater than all elements on left of it, i.e., 
                // price[0], price[1], ..price[i-1]. Else price[i] 
                // is greater than elements after top of stack 
                S[i] = (st.Count == 0) ? (i + 1) : (i - (int)st.Peek());

                // Push this element to stack 
                st.Push(i);
            }
        }

        // A utility function to print elements of array 
        static void printArray(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
                Console.Write(arr[i] + " ");
        }

        // Driver method 

    }
}


