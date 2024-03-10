class Timer {
   public:
    virtual ~Timer() {}
    virtual void Start(int timeout_ms) = 0;
    virtual void Stop() = 0;
    virtual bool IsRunning() const = 0;
};
