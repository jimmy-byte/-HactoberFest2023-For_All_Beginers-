<script>
class Node {
	constructor(val) {
		this.key = val;
		this.left = null;
		this.right = null;
	}
}

	var root = null;
	function printPostorder(node) {
		if (node == null)
			return;

		// first recur on left subtree
		printPostorder(node.left);

		printPostorder(node.right);
		document.write(node.key + " ");
	}
	function printInorder(node) {
		if (node == null)
			return;

		printInorder(node.left);

		document.write(node.key + " ");

		printInorder(node.right);
	}

	function printPreorder(node) {
		if (node == null)
			return;

	
		document.write(node.key + " ");

		printPreorder(node.left);

	
		printPreorder(node.right);
		
	}


	
	
		root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);

		document.write("Preorder traversal of binary tree is <br/>");
		printPreorder(root);

		document.write("<br/>Inorder traversal of binary tree is <br/>");
		printInorder(root);

		document.write("<br/>Postorder traversal of binary tree is <br/>");
		printPostorder(root);

// This code is contributed by aashish1995
</script>
