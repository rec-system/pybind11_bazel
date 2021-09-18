#include "cpp_class/adder.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

namespace py = pybind11;

PYBIND11_MODULE(adder_extension, m) {
  py::class_<Adder>(m, "Adder")
      .def(py::init<int, int>())
      .def("sum", &Adder::sum)
      .def("get", &Adder::get, py::return_value_policy::copy);
  py::class_<TestData>(m, "TestData")
      .def(py::init<uint64_t>(), py::arg("num")=2048)
      .def_readwrite("data", &TestData::data);
    py::class_<FeaRet>(m, "FeaRet")
        .def(py::init<uint64_t>(), py::arg("num")=2048)
        .def_readwrite("dense_vec", &FeaRet::dense_vec)
        .def_readwrite("cat_vec", &FeaRet::cat_vec);
}
