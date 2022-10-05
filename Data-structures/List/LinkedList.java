import java.util.*;

class LLNode{

	int data;
	LLNode next;
	
	LLNode(int data)
	{
		this.data=data;
		this.next=null;
		
	}
}


class Demo{
	
	LLNode head;
	
	
	LLNode insertInBeg(int key,LLNode head)
	{
		LLNode ttmp=new LLNode(key);
		
		if(head==null)
			head=ttmp;
		
		else
			{
				ttmp.next=head;
				head=ttmp;
			}
		return head;
	}
	
	
	LLNode insertInEnd(int key,LLNode head)
	{
		LLNode ttmp=new LLNode(key);
		LLNode ttmp1=head;
		
		if(ttmp1==null)
			head=ttmp;
		else
		{
			while(ttmp1.next!=null)
					ttmp1=ttmp1.next;
			ttmp1.next=ttmp;
			
		}
		
		return head;
			
	}


	LLNode insertAtPos(int key,int pos,LLNode head)
	{
		LLNode ttmp=new LLNode(key);
		
		if(pos==1)
		{
			ttmp.next=head;
			head=ttmp;
		}
		else
		{
			LLNode ttmp1=head;
			for(int i=1;ttmp1!=null && i<pos;i++)
				ttmp1=ttmp1.next;
			ttmp.next=ttmp1.next;
			ttmp1.next=ttmp;
		}
		
		return head;
	}
	
	
	LLNode delete(int pos,LLNode head)
	{
		LLNode ttmp=head;
		if(pos==1)
			head=ttmp.next;
		else
		{
			for(int i=1;ttmp!=null && i<pos-1;i++)
				ttmp=ttmp.next;
			ttmp.next=ttmp.next.next;
		}
		return head;
	}
	
	int length(LLNode head)
	{
		LLNode ttmp=head;
		int c=0;
		if(ttmp==null)
			return 0;
		else
		{
		 while(ttmp!=null)
			{	ttmp=ttmp.next;
				c++;
			}
		}
		return c;
	}
	
	
	LLNode reverse(LLNode head)
	{
		LLNode prevLNode=null,curLNode=head,nextLNode=null;
		while(curLNode!=null)
		{
			nextLNode=curLNode.next;
			curLNode.next=prevLNode;
			
			prevLNode=curLNode;
			curLNode=nextLNode;
		}
		
		head=prevLNode;
		return head;
	}
	
	
	void display(LLNode head)
	{
		LLNode ttmp=head;
		while(ttmp!=null)
			{System.out.print(ttmp.data+" ");
			 ttmp=ttmp.next;
			}
	}
	
	public static void main(String[] args)
	{
		LinkedListDemo l=new LinkedListDemo();
		l.head=null;
		Scanner in=new Scanner(System.in);
		 do
	{
 System.out.println("\n********* MENU *********");
	 System.out.println("\n1.Insert In End");
	 System.out.println("\n2.Insert In Beg");
	 System.out.println("\n3.Insert At A  Particular Pos");
	 System.out.println("\n4.Delete At a Pos");
	 System.out.println("\n5.Length");
	 System.out.println("\n6.Reverse");
	 System.out.println("\n7.Display");
	 System.out.println("\n8.EXIT");
	 System.out.println("\nenter ur choice : ");
	 int n=in.nextInt();
	 switch(n)
		{case 1: System.out.println("\nenter the value ");
			  l.head=l.insertInEnd(in.nextInt(),l.head);
			 break;
		 case 2: System.out.println("\nenter the value");
			 l.head=l.insertInBeg(in.nextInt(),l.head);
			 break;
		 case 3: System.out.println("\nenter the value");
			 l.head=l.insertAtPos(in.nextInt(),in.nextInt(),l.head);
			 break;
		 case 4: 
			 l.head=l.delete(in.nextInt(),l.head);
			 break;
		 case 5: 
			System.out.println(l.length(l.head));
			 break;
		 case 6: 
			 l.head=l.reverse(l.head);
			 break;
		 case 7: 
			l.display(l.head);
		 		 break;
		 case 8: System.exit(0);
		 		 break;
		 default: System.out.println("\n Wrong Choice!");
		 		  break;
		}
	 System.out.println("\n do u want to cont... ");
	}while(in.nextInt()==1);

 }
}
