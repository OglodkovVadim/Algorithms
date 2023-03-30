#include <iostream>
#include <list>
#include <string>

// struct of node
class Object
{
public:
	std::string name;
	std::list<Object> friends;
	Object(const std::string name, std::list<Object> friends) : name(name), friends(friends) {};
	Object(const std::string name) : name(name) {};

};

std::string BFS(std::list<Object>& queue, std::string findName)
{
	while (queue.size() != 0) {
		if (queue.front().name != findName) {
			for (auto& var : queue.front().friends)
				queue.push_back(var);
			queue.pop_front();
		}
		else
			return queue.front().name;
	}
	return "Not found";
}

int main()
{
  // create graph using our node - class Object
	Object obj1("People_1", std::list<Object> {Object("People_4"), Object("People_7"), Object("People_10")});
	Object obj2("People_2", std::list<Object> {Object("People_5"), Object("People_8"), Object("People_11")});
	Object obj3("People_3", std::list<Object> {Object("People_6"), Object("People_9"), Object("People_12")});
  // create main node to link graph's branches
	Object obj("Me", std::list<Object> {Object(obj1.name, obj1.friends), Object(obj2.name, obj2.friends), Object(obj3.name, obj3.friends)});

	std::list<Object> queue;
	std::string findName = "Kevin";

	queue.push_back(obj);
	std::cout << BFS(queue, findName) << std::endl;


	return 0;
}
