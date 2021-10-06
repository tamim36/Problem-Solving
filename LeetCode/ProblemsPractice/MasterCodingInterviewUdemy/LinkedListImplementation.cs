using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.MasterCodingInterviewUdemy
{
    public class LinkedListImplementation
    {
        Node node;
        LinkedListImplementation()
        {
            this.node = new Node();
        }

        struct Node
        {
            int value;
            int pointer;
        }
    }
}
