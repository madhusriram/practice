#ifndef _TEMPLATE_H
#define _TEMPLATE_H

template <typename T>
class Template {
	public:
		T x;
		
		void set(T v);

		T get();
};

#include "template_impl.hh"

#endif
