
#include <iostream>
#include <list>
#include <ostream>
#include <string>

class IEventListener {
    public:
    virtual ~IEventListener() = default;
    virtual void on_event(const std::string &message) = 0;
};

class IEventProducer {
    public:
    virtual ~IEventProducer() = default;
    virtual void add_event_listener(IEventListener *listener) = 0;
    virtual void remove_event_listener(IEventListener *listener) = 0;
    virtual void emit(const std::string &message) = 0;
};

class EventProducer : public IEventProducer {
    std::list<IEventListener *> listeners;

    public:
    ~EventProducer() override {
        std::cout << "delete EventProducer()" << std::endl;
    };

    void add_event_listener(IEventListener *listener) override {
        std::cout << "EventProducer::add_event_listener()" << std::endl;
        listeners.push_back(listener);
    }
    void remove_event_listener(IEventListener *listener) override {
        std::cout << "EventProducer::remove_event_listener()" << std::endl;
        listeners.remove(listener);
    }
    void emit(const std::string &message) override {
        auto iterator = listeners.begin();
        while (iterator != listeners.end()) {
            (*iterator)->on_event(message);
            ++iterator;
        }
    }
};

class EventListener : public IEventListener {
    public:
    ~EventListener() override = default;

    void on_event(const std::string &message) override {
        std::cout << "on_event(): " << message << std::endl;
    }
};
int main(int argc, char *argv[]) {
    EventProducer producer;
    EventListener listener;
    producer.add_event_listener(&listener);

    for (int i = 1; i < 100; ++i) {
        producer.emit("Numero: " + std::to_string(i));
    }

    producer.remove_event_listener(&listener);
}
