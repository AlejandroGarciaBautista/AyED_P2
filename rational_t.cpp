// AUTOR: Alejandro García Bautista
// FECHA: 
// EMAIL: alu0101387604@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
inline
int
rational_t::get_num() const
{
  return num_;
}



inline
int
rational_t::get_den() const
{
  return den_;
}


  
void
rational_t::set_num(const int n)
{
  num_ = n;
}


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



inline
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}



rational_t 
rational_t::opposite() const
{ 
  return rational_t((-1)*get_num(), get_den());
}



rational_t
rational_t::reciprocal() const
{ 
  return rational_t(get_den(), get_num());
}



// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  return fabs(value() - r.value()) < precision;
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return (value() - r.value()) > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return r.is_greater(*this, precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r) const
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}



rational_t
rational_t::substract(const rational_t& r) const
{
  return add(r.opposite());
}



rational_t
rational_t::multiply(const rational_t& r) const
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}



rational_t
rational_t::divide(const rational_t& r) const
{
  return multiply(r.reciprocal());
}


// FASE I: operadores
rational_t
operator+(const rational_t& a, const rational_t& b)
{
  rational_t add_result;
  if (a.get_den() == b.get_den()){
    add_result.set_num(a.get_num() + b.get_num());
    add_result.set_den(a.get_den());
  }else {
    add_result.set_den(a.get_den() * b.get_den());
    add_result.set_num(a.get_num() * b.get_den() + a.get_den() * b.get_num());
  }
  return add_result;
}



rational_t
operator-(const rational_t& a, const rational_t& b)
{
  rational_t sub_result;
  if (a.get_den() == b.get_den()){
    if (b.get_num() > a.get_num()){
      sub_result.set_den(a.get_den());
      sub_result.set_num(b.get_num() - a.get_num());
    }else{
      sub_result.set_den(a.get_den());
      sub_result.set_num(a.get_num() - b.get_num());
    }
  }else{
    if (b.get_num() > a.get_num()){
      sub_result.set_den(a.get_den() * b.get_den());
      sub_result.set_num(a.get_den() * b.get_num() - a.get_num() * b.get_den());
    }else{
      sub_result.set_den(a.get_den() * b.get_den());
      sub_result.set_num(b.get_den() * a.get_num() - b.get_num() * a.get_den());
    }
  }
  return sub_result;
}



rational_t
operator*(const rational_t& a, const rational_t& b)
{
  rational_t times_result;
  times_result.set_num(a.get_num() * b.get_num());
  times_result.set_den(a.get_den() * b.get_den());
  return times_result;
}



rational_t
operator/(const rational_t& a, const rational_t& b)
{
  rational_t division_result;
  division_result.set_num(a.get_num() * b.get_den());
  division_result.set_den(a.get_den() * b.get_num());
  return division_result;
}



// E/S
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void
rational_t::read(istream& is)
{
  is >> num_ >> den_;
  assert(den_ != 0);
}



ostream&
operator<<(ostream& os, const rational_t& r)
{
  r.write(os);
  return os;
}


istream&
operator>>(istream& is, rational_t& r)
{
  r.read(is);
  return is;
}
