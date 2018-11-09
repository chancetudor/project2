/*** green binary search tree class ***/

#ifndef __GST_INCLUDED__
#define __GST_INCLUDED__

#include <stdio.h>
#include "tnode.h"
#include "bst.h"

// stores a comparator function pointer in GST struct
typedef int (*CM)(void * one, void * two);
// stores a displayMethod function pointer in GST struct
typedef void (*DM)(void * ptr, FILE *fp);
// stores a swapper function pointer in GST struct
typedef void (*SM)(TNODE * one, TNODE * two);
// stores a freeMethod function pointer in GST struct
typedef void (*FM)(void * ptr);
typedef struct gst GST;
struct gst {
  BST * tree;
  int items;
  DM display;
  CM compare;
  FM freeMethod;
  SM swap;
};

extern GST   *newGST(int (*c)(void *,void *));
extern void   setGSTdisplay(GST *t,void (*d)(void *,FILE *));
extern void   setGSTswapper(GST *t,void (*s)(TNODE *,TNODE *));
extern void   setGSTfree(GST *t,void (*)(void *));
extern TNODE *getGSTroot(GST *t);
extern void   setGSTroot(GST *t,TNODE *replacement);
extern void   setGSTsize(GST *t,int s);
extern TNODE *insertGST(GST *t,void *value);
extern void  *findGST(GST *t,void *key);
extern TNODE *locateGST(GST *t,void *key);
extern int    deleteGST(GST *t,void *key);
extern TNODE *swapToLeafGST(GST *t,TNODE *node);
extern void   pruneLeafGST(GST *t,TNODE *leaf);
extern int    sizeGST(GST *t);
extern void   statisticsGST(GST *t,FILE *fp);
extern void   displayGST(GST *t,FILE *fp);
extern int    debugGST(GST *t,int level);
extern void   freeGST(GST *t);

/* extensions of BST */
extern void   *unwrapGST(TNODE *n);
extern int    freqGST(GST *g,void *key);
extern int    duplicatesGST(GST *g);

#endif /* gst.h */
