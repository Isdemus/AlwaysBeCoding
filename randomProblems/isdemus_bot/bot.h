class bot {
  public:
    bot() : remaining_t(900) {};
    void change_t(unsigned int t);
    unsigned int get_t();
    void makeAMove();
    void drawRequest();
    void surrender();

  private:
    unsigned int remaining_t;
    float probability;
};
