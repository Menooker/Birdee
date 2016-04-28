#ifndef PUBLIC_DBG_H_INCLUDED
#define PUBLIC_DBG_H_INCLUDED
#include <stdio.h>
#include <stdarg.h>



#ifdef __cplusplus
extern "C"
{
#endif

typedef struct DBG_Controller_tag *DBG_Controller;


#ifdef DBG_NO_DEBUG
#define DBG_create_controller()         ((void)0)
#define DBG_set_debug_level(level)      ((void)0)
#define DBG_set_debug_write_fp(fp)      ((void)0)
#define DBG_assert(expression, arg)     ((void)0)
#define DBG_panic(arg)                  ((void)0)
#define DBG_debug_write(arg)            ((void)0)
#else /* DBG_NO_DEBUG */
#ifdef DBG_CONTROLLER
#define DBG_CURRENT_CONTROLLER  DBG_CONTROLLER
#else /* DBG_CONTROLLER */
#define DBG_CURRENT_CONTROLLER  dbg_default_controller
#endif /* DBG_CONTROLLER */
extern DBG_Controller DBG_CURRENT_CONTROLLER;

#define DBG_create_controller() (DBG_create_controller_func())
#define DBG_set_debug_level(level) \
(DBG_set_debug_level_func(DBG_CURRENT_CONTROLLER, (level)))
#define DBG_set_debug_write_fp(fp) \
(DBG_set_debug_write_fp(DBG_CURRENT_CONTROLLER, (fp))
#define DBG_assert(expression, arg) \
 ((expression) ? (void)(0) :\
  ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
   (DBG_set_expression(#expression)),\
   DBG_assert_func arg))
#define DBG_panic(arg) \
 ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
  DBG_panic_func arg)
#define DBG_debug_write(arg) \
 ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
  DBG_debug_write_func arg)
#endif /* DBG_NO_DEBUG */

typedef enum {
    DBG_TRUE = 1,
    DBG_FALSE = 0
} DBG_Boolean;


extern struct DBG_Controller_tag * dbg_default_controller;
extern void DBG_set(DBG_Controller controller, char *file, int line);
extern void DBG_set_expression(char *expression);
extern DBG_Controller DBG_create_controller_func(void);
extern void DBG_set_debug_level_func(DBG_Controller controller, int level);
extern void DBG_set_debug_write_fp_func(DBG_Controller controller, FILE *fp);
extern void DBG_assert_func(char *fmt, ...);
extern void DBG_panic_func(char *fmt, ...);
extern void DBG_debug_write_func(int level, char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* PUBLIC_DBG_H_INCLUDED */
