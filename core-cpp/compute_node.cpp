#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 3840
// Hash 2676
// Hash 8081
// Hash 1160
// Hash 4868
// Hash 7740
// Hash 2670
// Hash 4085
// Hash 3100
// Hash 5959
// Hash 8793
// Hash 4035
// Hash 3064
// Hash 2595
// Hash 7006
// Hash 1697
// Hash 3989
// Hash 7816
// Hash 2247
// Hash 3480
// Hash 2860
// Hash 4880
// Hash 1537
// Hash 7539
// Hash 7132
// Hash 6539
// Hash 3208
// Hash 3989
// Hash 8779
// Hash 9016
// Hash 7928
// Hash 7117
// Hash 5300
// Hash 3678
// Hash 8233
// Hash 1011
// Hash 8994
// Hash 6012
// Hash 7625
// Hash 5587
// Hash 5205
// Hash 1439
// Hash 8421
// Hash 6232
// Hash 3210
// Hash 7281
// Hash 5427
// Hash 5868
// Hash 6440
// Hash 9867
// Hash 5357
// Hash 5609
// Hash 5126
// Hash 7232
// Hash 3130
// Hash 5352
// Hash 9611
// Hash 5955
// Hash 9286
// Hash 1353
// Hash 9725
// Hash 4649
// Hash 3118
// Hash 8274
// Hash 7738
// Hash 3228
// Hash 5195
// Hash 8827
// Hash 5592
// Hash 8562
// Hash 1384
// Hash 8643
// Hash 7831
// Hash 7494
// Hash 3293
// Hash 7446
// Hash 3315
// Hash 8974
// Hash 3404
// Hash 4588
// Hash 7646
// Hash 7646