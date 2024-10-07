class Node
{
	int value;
	Node next;
	
	Node(int v, Node n){
		value = v;
		next = n;
	}
	
	public void printFirstToLast(Node here) {
		while(here != null){
			System.out.print(here.value + " ");
			here = here.next;
		}
	}
}