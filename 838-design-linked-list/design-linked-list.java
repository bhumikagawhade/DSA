class MyLinkedList {

    public static class Node{
            int val;
            Node next;
            Node(int val){
                this.val = val;
                this.next = null;
            }
    }

    public  Node head ;
    public  Node tail ; 

    public int length(){
        int len = 0;
        Node temp = head;
        while(temp != null){
            temp=temp.next;
            len++;
        }
        return len;
    }

    public MyLinkedList() {
        head = null;
        tail = null;
    }
    
    public int get(int index) {
        int len = length();
        if(index <0 || index >= len){
            return -1;
        }

        // if(index == 0){
        //     return head.next.val;

        // }

        // if( index == len-1){
        //     return tail.val;
        // }

       
            Node temp = head;
            for(int i=0;i<index;i++){
                temp = temp.next;
            }

        return temp.val;

    }
    
    public void addAtHead(int val) {
        if(head == null && tail == null){
            Node newnode = new Node(val);
            head = newnode;
            tail = newnode;

        }

        else{
            Node newnode = new Node(val);
            newnode.next = head;
            head=newnode;
        }
    }
    
    public void addAtTail(int val) {
        if(head == null && tail == null){
            Node newnode = new Node(val);
            head = newnode;
            tail = newnode;
        }
        else{
            Node newnode = new Node(val);
            tail.next = newnode;
            tail = newnode;
        }
    }
    
    public void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        int len = length();
        if(index == len){
            addAtTail(val);
            return;
        }

        if (index > len || index < 0) return;

        else{
            Node newnode = new Node(val);
            Node temp = head;

            for(int i=0;i<index-1;i++){
                temp = temp.next;
            }

            newnode.next = temp.next;
            temp.next=newnode;
        }

    }
    
    public void deleteAtIndex(int index) {
        int len = length();
        if (index < 0 || index >= len) {
            return; 
        }
        if(index == 0){
            Node temp = head;
            head = head.next;
            temp.next = null;

            if (head == null) {
                tail = null;
            }
            
            return ;
        }

        else{
            Node prev = head;
            for(int i=0;i<index-1;i++){
                prev = prev.next;
            }

            Node curr = prev.next;
            Node forward = curr.next;

            if (curr == tail) {
                tail = prev;
            }

            curr.next = null;
            prev.next = forward;
            
            
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */