#include <iostream>
#include "dbuff.h"

int main(int argc, char *argv[]) {

	dbuff::dynamic_buffer db, db2;

	dbuff::initialize(db);

	dbuff::stampaBuffer(db);

	dbuff::allocate_dynamic_buffer(db,3);

	dbuff::set_value_dynamic_buffer(db,20);

	dbuff::stampaBuffer(db);

	//db2 = db; // non crea dbuffer indipendenti

	db2 = dbuff::clone_dynamic_buffer(db);

/*	dbuff::dynamic_buffer *db3 = 0;
	db3 = dbuff::clone_dynamic_buffer(db);*/

	//dbuff::clone_dynamic_buffer(db,db2);

	dbuff::deallocate_dynamic_buffer(db);
	dbuff::deallocate_dynamic_buffer(db2);
	//dbuff::deallocate_dynamic_buffer(*db3);
  //delete db3;

	return 0;
}
