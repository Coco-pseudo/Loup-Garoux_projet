#include "index.h"

#ifndef NARRATEUR
#define NARRATEUR

    /*!
     * \fn debut()
     * \brief première phrase du premier tour (le tour de démarrage et le tour 1)
     */
    void debut();

    /*! 
     * \fn appel(int role, int debut)
     * \brief écrit la phrase type de réveil (debut == TRUE) ou pour s'endormir (debut == FALSE) des différents roles (VOYANTE, SORCIERE, LOUPGAROUS ...)
     */
    void appel(int role, int debut);

#endif 