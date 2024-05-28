Embedded Interns -2024 Data Structures SRA 11 Date: 14/5/2024

Expectation: 
• Write Unit Test Case
• Apply Coding Standards
• Implement the task
1. Employees and BreakFast
At the EIC Cafeteria, n employees are standing in the queue. Today, on the menu, we have 
either a plain dosa or a masala dosa. Each employee has a preference. He/She either want to
eat a sada dosa or a masala dosa. At the front end of the queue, there is a stack of dosas, a 
mix of sada and masala dosas. A employee at the front of the queue performs the following 
operation
1. If the employee likes a sada dosa and the top of the stack is a sada dosa, then the 
employee takes the sada dosa and leaves the queue.
2. If the employee likes a masala dosa and the top of the stack is a masala dosa, then the
employee takes the masala dosa and leaves the queue.
3. Else the employee leaves the front of the queue and goes to end of the queue.
This process goes on till no one in the queue is able to leave it. All these employees will not 
be able to have the breakfast today. Your job is to find the number of such employees.
Input: In the input O(zero) will be used to represent a sada dosa and 1(one) represents a 
masala dosa. The first line of the input contains single integer n(1 ≤ n ≤ 10000), the number
of employees in the queue as well as the number of dosas on the stack. The next line 
contains n integers (only 1 and 0) separated by a space. This sequence represents the stack 
where the first element is the top of the stack. The third line contains n numbers a1, a2, . . . ,
      an( Each ai is 1 and 0). The first number represents the first person of the queue who like sada
      dosa if a1 = 0 or masala dosa if a1 = 1.
      Output: The number of employees who will not be able to
      have the breakfast. 
      Input : 3
      0 1 1
      1 0 1
      Output : 0
      Explanation: The following happensin each iteration:
      1. The employee at the front goes to the back. The stack is now [0 1 1] and queue is [0 1 1].
      2. The employee at the front takes the sada dosa. The stack is now [1 1] and queue is [1 1].
      3. The employee at the front takes the masala dosa. The stack is now [1] and queue is [1].
      4. The employee at the front takes the masala dosa. The stack is now [] and queue is [].
      2. Nodes Under the Subtree
      You are given a binary tree rooted at a node, say node number 1. For each node x in this tree, 
      you have to print the number of nodes in the subtree rooted at x (note that the subtree also 
		      contains the node x).
      Input: The first line contains single integer n(1 ≤ n ≤ 10000)— the number of nodes in the tree.
      The nodes in the tree are numbered from 1 to n. The root of the tree will be node 1.
      The next n lines have two numbers separated by a space. The number x y in line i (one of these
		      n lines) denotes the left and right child of node i in the tree respectively. For example, for the ith node, we may have the following:
      1. 5 3
      This implies that the left child of node i is 5 and the right child is 3.
      2. 0 3
      This implies that node i has no left child but its right child is 3.
      3. 0 0
      This implies that node i has no left or right child.
      Output: Let ai denote the number of nodes in the subtree rooted at node i. Then the
      output is the sequence
      a1 a2 . . . an separated by a
      space. 
      Input : 3
      2 3
      0 0
      0 0
      Output : 3 1 1
      Explanation: In this tree, the root node 1 has one left child, that is node 2, and one right child, 
      that is node 3. Node 2 and Node 3 have no children. Thus, the number of nodes in the subtree 
      of node 1 is 3. The number of nodes in the subtree of node 2 and node 3 is 1.
