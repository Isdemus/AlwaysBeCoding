enum occupation {
  Pon,
  Rook,
  Knight,
  Bishop,
  Queen,
  King
};

typedef struct location {
  unsigned int row;
  unsigned int col;
}Location;

class unit {
  public:
    Location* possibleMoves();

  private:
    Location currentLocation;
    Location lastLocation;
    occupation kind;  
};
