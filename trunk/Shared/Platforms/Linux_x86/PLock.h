//******************************************************************************
// Copyright 2012  Zheltovskiy Andrey                                          *
//                                                                             *
//   Licensed under the Apache License, Version 2.0 (the "License");           *
//   you may not use this file except in compliance with the License.          *
//   You may obtain a copy of the License at                                   *
//                                                                             *
//       http://www.apache.org/licenses/LICENSE-2.0                            *
//                                                                             *
//  Unless  required  by  applicable  law  or  agreed  to in writing, software *
//  distributed  under the License is distributed on an "AS IS" BASIS, WITHOUT *
//  WARRANTIES  OR  CONDITIONS OF ANY KIND, either express or implied. See the *
//  License  for  the  specific language governing permissions and limitations *
//  under the License.                                                         *
//                                                                             *
//******************************************************************************

#ifndef PLOCK_H_AZH
#define PLOCK_H_AZH

#include <pthread.h>

///////////////////////////////////////////////////////////////////////////////
typedef pthread_mutex_t           tLOCK;


#define  LOCK_CREATE(i_Lock)       {\
                                       pthread_mutexattr_t l_sAttr;\
                                       memset(&l_sAttr, 0, sizeof(pthread_mutexattr_t));\
                                       pthread_mutexattr_init(&l_sAttr);\
                                       pthread_mutexattr_settype(&l_sAttr,\
                                                                 PTHREAD_MUTEX_RECURSIVE);\
                                       pthread_mutex_init(&i_Lock, &l_sAttr);\
                                       pthread_mutexattr_destroy(&l_sAttr);\
                                   }\


#define  LOCK_DESTROY(i_Lock)      pthread_mutex_destroy(&i_Lock)                

#define  LOCK_ENTER(i_Lock)        pthread_mutex_lock(&i_Lock)                
#define  LOCK_EXIT(i_Lock)         pthread_mutex_unlock(&i_Lock)

#endif //PLOCK_H_AZH
