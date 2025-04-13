compile : 
	g++ main.cpp Sender.cpp DeliveryStaff.cpp BinaryTree.cpp Node.cpp LL.cpp User.cpp -o nearme
run : 
	./nearme
test : 
	g++ test.cpp -o test 

