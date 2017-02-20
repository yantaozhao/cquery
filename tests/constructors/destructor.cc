class Foo {
public:
  Foo() {}
  ~Foo() {};
};

void foo() {
  Foo f;
}

// TODO: Support destructors (notice how the dtor has no usages listed).
//        - check if variable is a pointer. if so, do *not* insert dtor
//        - check if variable is normal type. if so, insert dtor
//        - scan for statements that look like dtors in function def handler
//        - figure out some way to support w/ unique_ptrs?
/*
OUTPUT:
{
  "types": [{
      "id": 0,
      "usr": "c:@S@Foo",
      "short_name": "Foo",
      "qualified_name": "Foo",
      "definition": "tests/constructors/destructor.cc:1:7",
      "funcs": [0, 1],
      "all_uses": ["tests/constructors/destructor.cc:1:7", "tests/constructors/destructor.cc:8:3"],
      "interesting_uses": ["tests/constructors/destructor.cc:8:3"]
    }],
  "functions": [{
      "id": 0,
      "usr": "c:@S@Foo@F@Foo#",
      "short_name": "Foo",
      "qualified_name": "Foo::Foo",
      "definition": "tests/constructors/destructor.cc:3:3",
      "declaring_type": 0,
      "callers": ["2@tests/constructors/destructor.cc:8:7"],
      "all_uses": ["tests/constructors/destructor.cc:3:3", "tests/constructors/destructor.cc:8:7"]
    }, {
      "id": 1,
      "usr": "c:@S@Foo@F@~Foo#",
      "short_name": "~Foo",
      "qualified_name": "Foo::~Foo",
      "definition": "tests/constructors/destructor.cc:4:3",
      "declaring_type": 0,
      "all_uses": ["tests/constructors/destructor.cc:4:3"]
    }, {
      "id": 2,
      "usr": "c:@F@foo#",
      "short_name": "foo",
      "qualified_name": "foo",
      "definition": "tests/constructors/destructor.cc:7:6",
      "callees": ["0@tests/constructors/destructor.cc:8:7"],
      "all_uses": ["tests/constructors/destructor.cc:7:6"]
    }],
  "variables": [{
      "id": 0,
      "usr": "c:destructor.cc@70@F@foo#@f",
      "short_name": "f",
      "qualified_name": "f",
      "definition": "tests/constructors/destructor.cc:8:7",
      "variable_type": 0,
      "all_uses": ["tests/constructors/destructor.cc:8:7"]
    }]
}
*/