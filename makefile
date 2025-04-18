compile : 
	g++ main.cpp Sender.cpp DeliveryStaff.cpp Node.cpp LL.cpp User.cpp -o nearme
run : 
	./nearme
test : 
	g++ test.cpp -o test 

