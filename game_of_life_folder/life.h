#ifndef LIFE_H
#define LIFE_H
//
//  INCLUDES
//
#include "vector"

/*! The game of life class */
class Life
{
private:
       //! Life array for calculations
//    std::vector<std::vector<bool>> array;
    std::vector<std::vector<bool>> array;
public:
    //! Life array for calculations height
    unsigned int array_h;
    //! Life array for calculations width
    unsigned int array_w;
    //! Life constructor which initializes life with 30x30 matrix.
    /*!
      \return life matrix object
    */
    Life();     //!< A life constructor.

    //! Life destructor. Do nothing
    ~Life();    //!< A life destructor

    //! Life constructor which initializes life with XxY matrix.
    /*!
      \param x - horisontal size of matrix
      \param y - vertical size of matrix
      \return life matrix object
    */
    Life(unsigned int x, unsigned int y);   //!< A life destructor. Initializes live matrix with spetial size.
    //! Sets cell (x, y) alive in life matrix.
    /*!
      \param x - horisontal cell coord in matrix
      \param y - vertical cell coord in matric
      \return true - cell coords in life matrix, false - cell coord out of life matrix
    */
    char Set_cell_alive(unsigned int x, unsigned int y);    //!< Sets cell alive

    //! Sets cell (x, y) dead in life matrix.
    /*!
      \param x - horisontal cell coord in matrix
      \param y - vertical cell coord in matric
      \return true - cell coords in life matrix, false - cell coord out of life matrix
    */
    char Set_cell_dead(unsigned int x, unsigned int y);     //!< Sets cell dead

    //! Returns if cell (x, y) alive in life matrix.
    /*!
      \param x - horisontal cell coord in matrix
      \param y - vertical cell coord in matric
      \return true - cell alive in life matrix, false - cell is dead or cell coord out of life matrix
    */
    bool Get_cell_life(unsigned int x, unsigned int y);     //!< Returns cell alive status

    //! Clears life cells
    /*!
     * \brief Clears life matrix array
     */
    void Clr();

    //!
    //! \brief Clclt - calculates Life matrix.
    //! \param array - pointer to new life
    //!
    void Clclt(Life * array);

    //!
    //! \brief operator = - overriden equation operator
    //! \param other_life - new live to be set
    //! \return reevaluate value of live
    //!
    Life& operator = (const Life &other_life);  //!< Equation opeerator override
};

#endif // LIFE_H
