/*
 * ============================================================================
 *
 *       Filename:  BT.h
 *
 *    Description:  BT class definition for binary tree application
 *
 *        Version:  0.4
 *        Created:  2014-03-23
 *   Last Updated:  2014-05-04
 *
 *         Author:  Zoltan Dalmadi
 *         E-mail:  dmz985@gmail.com
 *
 * ============================================================================
 *
 *      Changelog:
 *
 *            0.1: initial release
 *            0.2: added C++11 features
 *            0.3: added copy constructor, assignment operator and copy
 *                 function definitions
 *            0.4: added move constructor and move assignment operator
 *                 definitions
 *
 * ============================================================================
 */

#ifndef BT_H
#define BT_H

class BT
{
private:

  // csomópont struktúra
  struct Node
  {
    // A csomópont értéke ('0' vagy '1')
    char value;

    // Bal gyermek mutató
    Node* left;

    // Jobb gyermek mutató
    Node* right;
  };

  // Csomópont készítő függvény
  Node* createNode(const char&);

  // Csomópont megsemmisítő függvény
  void destroyNode(Node*);

  // Privát csomópont hozzáadó függvény
  void addNodePrivate(const char&, Node*);

  // Gyökér csomópontra mutató mutató
  Node* root;

  // Aktuális csomópontra mutató mutató
  Node* currentNode;

  // Fa mélysége
  int treeHeight;

  // Fa maximális mélysége
  int maxTreeHeight;

  // Átlagszámításhoz szükséges változók
  double average;
  int averageTemp;
  int averageSum;

  // Szórásszámításhoz szükséges változók
  double variance;
  double varianceSum;

  // Mélységet lekérő függvény
  int getHeight(Node*);

  // Mélységet számító függvény
  void calculateHeight(Node*);

  // Átlagot lekérő függvény
  double getAverage(Node*);

  // Átlagot számító függvény
  void calculateAverage(Node*);

  // Szórást lekérő függvény
  double getVariance(Node*);

  // Szórást számító függvény
  void calculateVariance(Node*);


public:
  // Konstruktor
  BT();

  // Destruktor
  ~BT();

  // Másoló konstruktor
  BT(const BT&);

  // Másoló értékadás (a.k.a. egyenlőségjel operátor)
  BT& operator= (const BT&);

  // Mozgató konstruktor
  BT(BT&&);

  // Mozgató értékadás (a.k.a. egyenlőségjel operátor)
  BT& operator= (BT&&);

  // rekurzív csomópont másoló függvény
  Node* copyNode(const Node*);

  // Publikus csomópont hozzáadó függvény
  void addNode(const char&);

  // Túlterheljük a << operátort, ugyanazt fogja csinálni, mint az előző
  // függvény, de így egyszerűbben lehet csomópontokat hozzáadni
  void operator<< (const char&);

  // Getter a gyökér csomóponthoz
  Node* getRoot() const;

  // Összes csomópontot kiíró függvény
  void printAllNodes(Node*, std::ostream&);

  // Mélységet kiíró függvény
  void printHeight(Node*, std::ostream&);

  // Átlagot kiíró függvény
  void printAverage(Node*, std::ostream&);

  // Szórást kiíró függvény
  void printVariance(Node*, std::ostream&);
};

#endif
