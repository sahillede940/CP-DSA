class MyList:
    class Node:
        def __init__(self, val):
            self.val = val
            self.next = None
    
    def __init__(self):
        self.size = 0
        self.head = None
    
    def push_front(self, val):
        new_node = self.Node(val)
        new_node.next = self.head
        self.head = new_node
        self.size += 1
        
    def push_back(self, val):
        if self.size == 0:
            self.push_front(val)
            return
        new_node = self.Node(val)
        cur = self.head
        while cur.next is not None:
            cur = cur.next
        cur.next = new_node
        self.size += 1
        
    def insert(self, index, val):
        if index < 0 or index >= self.size:
            return
        if index == 0:
            self.push_front(val)
            return
        cur = self.head
        for i in range(index - 1):
            cur = cur.next
        new_node = self.Node(val)
        new_node.next = cur.next
        cur.next = new_node
        self.size += 1
        
    def print_list(self):
        cur = self.head
        while cur is not None:
            print(cur.val, end=' ')
            cur = cur.next
        print()
        
    def erase(self, index):
        if index < 0 or index >= self.size:
            return
        to_del = None
        if index == 0:
            to_del = self.head
            self.head = self.head.next
        else:
            cur = self.head
            for i in range(index - 1):
                cur = cur.next
            to_del = cur.next
            cur.next = cur.next.next
        self.size -= 1
        del to_del
        
# Example Usage:
A = MyList()
A.push_front(34)
A.push_front(23)
A.push_front(3453)
A.push_front(56)
A.push_back(42)
A.insert(2, 123)
A.print_list()
A.erase(2)
A.erase(1)
A.print_list()
