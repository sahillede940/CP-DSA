class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.cnt = 0


class BST:
    def __init__(self):
        self.root = None

    def insert(self, val):
        def rec(root):
            if root == None:
                return Node(val)
            elif val == root.val:
                root.cnt += 1
            elif val < root.val:
                root.left = rec(root.left)
            else:
                root.right = rec(root.right)
            return root

        self.root = rec(self.root)

    def getRoot(self):
        return self.root

    def find(self, val):
        def rec(node, val):
            if node is None:
                return print(False)
            if val == node.val:
                return print(True)
            elif val < node.val:
                return rec(node.left, val)
            else:
                return rec(node.right, val)

        return rec(self.root, val)

    def bfs_print(self):
        if self.root == None:
            return
        queue = [self.root]
        while len(queue) > 0:
            node = queue.pop(0)
            print(node.val, end=" ")
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)


tree = BST()
tree.insert(12)
tree.insert(2)
tree.insert(125)
tree.insert(426)
tree.insert(45)
tree.insert(33)
tree.insert(997)
tree.insert(1)
tree.insert(42)
tree.insert(42)
tree.insert(999)
tree.bfs_print()
print()
tree.find(999)
tree.find(99)
