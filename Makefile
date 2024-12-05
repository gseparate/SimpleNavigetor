all:
	# g++ -Wall -Wextra -g -std=c++17 -Werror -c lib/list/team_list.h lib/stack/team_stack.h lib/queue/team_queue.h
	# ar rcs libteam_list.a lib/list/team_list.h.gch #lib/stack/team_stack.h.gch lib/queue/team_queue.h.gch  
	g++ *.cc -o graph
	# g++ main.cc -o graph
	# valgrind ./graph
	./graph