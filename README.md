## How to run everything:
1) Open Developer Command Prompt for VS 2022.
2) Run cd "path to the project directory" to move to the proper directory
3) Run nmake all to execute everything. It will automatically run BSTtest and replace
4) Run nmake clean to clean project

## Used toolchain:
	Microsoft (R) C/C++ Optimizing Compiler Version 19.34.31937 for x86
	Microsoft (R) Incremental Linker Version 14.34.31937.0

## BSTtest.exe:
	test all BST methods and output results to the console

## replace.exe:
	replace defined constants in .c file(passed as first argument) with their values and write them in .o file

## BST Library:
	BST::BST(): Constructor of the BST class that initializes the root to nullptr.

	BST::BST(const BST& other): Copy constructor that creates a deep copy of another BST object.

	BST::~BST(): Destructor that frees the memory of the binary search tree using destroy_tree helper function.

	string BST::to_string() const: Method that returns a string representation of the binary search tree using to_string_helper.

	void BST::insert_constant(string name, string value): Method to insert a new node with the specified name and value into the binary search tree.

	string BST::get_value(string name) const: Method to retrieve the value associated with the specified name from the binary search tree.

	int BST::num_constants() const: Method that returns the number of constants in the binary search tree using count_num.

	BST& BST::operator=(const BST& rhs): Assignment operator that creates a deep copy of another BST object.

github:
	https://github.com/Drakon4ik-Coder/BST
