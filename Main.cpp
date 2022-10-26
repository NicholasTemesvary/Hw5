#include <iostream>
#include <vector>

template <class T>
class vect_queue 
{
    std::vector<T> vect_que;
    size_t size_;
    int que_front_;
    int que_back_;

    public:
        vect_queue<T>(T val) 
        {
        vect_que.push_back(val);
            size_ = 1;
            que_front_ = 0;
            que_back_ = 0;
        }

    int map(int i) 
    {
        int j = 0;
        if (vect_que.size() != 0) 
        {
            if (que_front_ + i < vect_que.size()) 
            {
                j = i + que_front_;
            }

            else 
            {
                j = i + que_front_ - vect_que.size();
            }
        }
        return j;
    }

        T front() const 
        {
            return vect_que[que_front_];
        }
        T back() const 
        {
            return vect_que[que_back_];
        }


        void deque() 
        {
            if (size_ > 1) 
            {
                size_--;
                vect_que[que_front_] = NULL;
                if (que_front_ == vect_que.size() - 1) 
                {
                    que_front_ = 0;
                }
                    else 
                {
                    que_front_++;
                }
            }
            else if (size_ == 1) 
            {
                size_--;
                vect_que[que_front_] = NULL;
                que_front_ = 0;
                que_back_ = 0;
            }
            else 
            {
                std::cout << "This action cannot be performed";
            }
            
        }

        void enque(T val) 
        {
            if (size_ < vect_que.size()) 
            {
                if (size_ == 0) 
                {
                    size_++;
                    vect_que[que_front_] = val;
                }

                else 
                {
                    size_++;
                    if (que_back_ != vect_que.size() - 1) 
                    {
                        vect_que[que_back_ + 1] = val;
                        que_back_++;
                    }
                    else 
                    { 
                        vect_que[0] = val;
                        que_back_ = 0;
                    }
                }
            }

            else if (size_ == vect_que.size()) 
            {
                std::vector<T> new_vect_que;
                if (vect_que.size() > 0) 
                {
                    new_vect_que.resize(vect_que.size() * 2);
                    for (int i = 0; i < size_; i++) 
                    {
                        new_vect_que[que_front_ + i] = vect_que[map(i)];
                    }
                    new_vect_que[que_front_ + size_] = val;
                    que_back_ = que_front_ + size_;
                    vect_que = new_vect_que;
                    size_++;
                }

                else 
                {
                    new_vect_que.resize(1);
                    new_vect_que.push_back(val);
                    que_back_ = 1;
                    vect_que = new_vect_que;
                    size_++;
                }
            }

            else 
            {
                std::cout << "Too big" << "\n\n";
            }
        }

        void print_vect() const 
        {
            for (int i = 0; i < vect_que.size(); i++)
            {
                std::cout << vect_que[i] << " ";
            }
            std::cout << "(Front: " << que_front_;
            std::cout << " Back: " << que_back_ << ")";
        }
};

int main() 
{
    //Case 1
    std::cout << "[Case 1] Adding to an empty queue:" << "\n";

    std::cout << "Before:\n";
    vect_queue<int> test(1);
    test.deque();
    test.print_vect();
    
    std::cout << "\n";

    std::cout << "After:\n";
    test.enque(1);
    test.print_vect();
    std::cout << "\n\n";

    
    //Case 2
    std::cout << "[Case 2] Add to a non-empty queue without jump:" << "\n";

    std::cout << "Before:\n";
    test.print_vect();
    
    std::cout << "\n";

    std::cout << "After:\n";
    test.enque(12);
    test.print_vect();
    std::cout << "\n\n";

    
    //Case 3
    std::cout << "[Case 3] Adding to a non-empty queue with a jump:" << "\n";

    std::cout << "Before:\n";
    test.deque();
    test.print_vect();

    std::cout << "\n";
    
    std::cout << "After:\n";
    test.enque(7);
    test.print_vect();
    std::cout << "\n\n";

    
    //Case 4
    std::cout << "[Case 4] Removing from a queue with number of elements > 1 and que.front not at vect.back: " << "\n";

    std::cout << "Before:\n";
    test.deque();
    test.deque();
    test.enque(5);
    test.enque(6);
    test.print_vect();

    std::cout << "\n";

    std::cout << "After:\n";
    test.deque();
    test.print_vect();
    std::cout << "\n\n";


    //Case 5
    std::cout << "[Case 5] Removing from a queue with number of elements > 1 and que.front at vect.back: " << "\n";

    std::cout << "Before:\n";
    test.enque(21);
    test.print_vect();
    
    std::cout << "\n";

    std::cout << "After:\n";
    test.deque();
    test.print_vect();
    std::cout << "\n\n";


    //Case 6
    std::cout << "[Case 6] Removing from a queue with 1 element in it and que.front not at vect[0]: " << "\n";

    std::cout << "Before:\n";
    test.enque(100);
    test.deque();
    test.print_vect();

    std::cout << "\n";

    std::cout << "After:\n";
    test.deque();
    test.print_vect();
    std::cout << "\n";

    std::cout << "\nProgram ends here.\n";
    return 0;
}
