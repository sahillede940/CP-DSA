class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.sz = 0

    def size(self):
        # Returns the sz of the list
        return self.sz

    def is_empty(self):
        # Returns True if the list is empty, False otherwise
        return self.head is None

    def append(self, data):
        # Adds a node with the given data to the end of the list
        new_node = Node(data)
        if self.is_empty():
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        self.sz += 1

    def prepend(self, data):
        # Adds a node with the given data to the start of the list
        new_node = Node(data)
        if self.is_empty():
            self.head = self.tail = new_node
        else:
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
        self.sz += 1

    def delete(self, data):
        # Deletes the first occurrence of a node with the given data
        cur = self.head
        while cur:
            if cur.data == data:
                if cur.prev:
                    cur.prev.next = cur.next
                else:
                    self.head = cur.next

                if cur.next:
                    cur.next.prev = cur.prev
                else:
                    self.tail = cur.prev

                return
            cur = cur.next

    def find(self, data):
        # Returns True if data is in the list, False otherwise
        cur = self.head
        while cur:
            if cur.data == data:
                return True
            cur = cur.next
        return False

    def print_list(self):
        # Prints the list in forward direction
        cur = self.head
        while cur:
            print(cur.data, end=' ')
            cur = cur.next
        print()


# Example Usage
dll = DoublyLinkedList()
dll.append(1)
dll.append(2)
dll.append(3)
dll.prepend(0)
print("List:", end=' ')
dll.print_list()

print("Length:", dll.size())
print("Is 2 in the list? : ", dll.find(2))

dll.delete(2)
print("List after deleting 2: ", end=' ')
dll.print_list()
