#ifndef MATRIX_HPP
#define MATRIX_HPP
#include<string>
#include <sstream>
#include <iostream>
#include <iomanip> 

template <class T>
class Matrix{
	public:
	void display(bool debug){
		for(auto i = 0u; i < m_rows; i++){
			for(auto j = 0u; j < m_cols; j++){
				std::cout << std::left << std::setw(5) << m_numbers[i][j];
				//TODO: make the setw change depending on length of number
			}
			std::cout << std::endl;
		}
		if(debug)
			std::cout << "[rows:" << m_rows << ", cols:"
				<< m_cols << ", addr:" << m_numbers << "]" << std::endl;
	}

	unsigned getCols(){ return m_cols; }

	T getDigit(const unsigned & i , const unsigned & j){
		return m_numbers[i][j];
	}

	unsigned getRows(){ return m_rows; }

	//default constructor makes a 3x3 identity matrix
	Matrix(): m_rows(3), m_cols(3), m_numbers(new T*[m_rows]){
		for(auto i = 0u; i < m_rows; i++){
			m_numbers[i] = new T[m_cols];
		}

		//populate with values
		for(auto i = 0u; i < m_rows; i++){
			for(auto j = 0u; j < m_cols; j++){
				m_numbers[i][j] = i==j ? 1 : 0;
			}
		}
	}

	Matrix(unsigned rows, unsigned cols, std::string nums): m_rows(rows),
	m_cols(cols), m_numbers(new T*[m_rows]){
		for(auto i = 0u; i < m_rows; i++){
			m_numbers[i] = new T[m_cols];
		}

		std::stringstream ss(nums);
		for(auto i = 0u; i < m_rows; i++){
			for(auto j = 0u; j < m_cols; j++){
				ss >> m_numbers[i][j];
			}
		}
	}

	//Copy constructor
	Matrix(const Matrix & rm): m_rows(rm.m_rows), m_cols(rm.m_cols),
	m_numbers(new T*[m_rows]){
		for(auto i = 0u; i < m_rows; i++){
			m_numbers[i] = new T[m_cols];
		}

		//populate with values
		for(auto i = 0u; i < m_rows; i++){
			for(auto j = 0u; j < m_cols; j++){
				m_numbers[i][j] = rm.m_numbers[i][j];
			}
		}
	}

	//Move constructor
	Matrix(Matrix && rm): m_rows(rm.m_rows), m_cols(rm.m_cols),
	m_numbers(rm.m_numbers){
		rm.m_rows = 3;
		rm.m_cols = 3;
		rm.m_numbers = new T*[rm.m_rows];

		for(auto i = 0u; i < rm.m_rows; i++){
			rm.m_numbers[i] = new T[rm.m_cols];
		}

		//populate with values
		for(auto i = 0u; i < rm.m_rows; i++){
			for(auto j = 0u; j < rm.m_cols; j++){
				rm.m_numbers[i][j] = i==j ? 1 : 0;
			}
		}

	}

	Matrix multiply(Matrix mat, T num){
		for(auto i = 0u; i < mat.getRows(); i++){
			for(auto j = 0u; j < mat.getCols(); j++){
				mat.setDigit(i, j, mat.getDigit(i, j) * num);
			}
		}

		return mat;
	}

	Matrix & operator = (const Matrix & rm){
		for(auto i = 0u; i < m_rows; i++){
			delete [] m_numbers[i];
			m_numbers[i] = nullptr;
		}
		delete [] m_numbers;
		m_numbers = nullptr;

		m_rows = rm.m_rows;
		m_cols = rm.m_cols;

		m_numbers =new T*[m_rows];
		for(auto i = 0u; i < m_rows; i++){
			m_numbers[i] = new T[m_cols];
		}

		//populate with values
		for(auto i = 0u; i < m_rows; i++){
			for(auto j = 0u; j < m_cols; j++){
				m_numbers[i][j] = rm.m_numbers[i][j];
			}
		}

		return *this;
	}

	Matrix operator * (T num){
		return multiply(*this, num);
	}

	Matrix operator +(Matrix rm){
		if (m_rows != rm.m_rows || m_cols != rm.m_cols)
			std::cerr << "UH OH! BAD ADDITION" << std::endl;
		//TODO: throw exception when this happens

		for(auto i = 0u; i < m_rows; i++){
			for(auto j = 0u; j < m_cols; j++){
				rm.m_numbers[i][j] += m_numbers[i][j];
			}
		}

		return rm;
	}



	void setDigit(const unsigned & i, const unsigned & j, T num){
		m_numbers[i][j] = num;
	};

	~Matrix(){
		for(auto i = 0u; i < m_rows; i++){
			delete [] m_numbers[i];
			m_numbers[i] = nullptr;
		}
		delete [] m_numbers;
		m_numbers = nullptr;
	}
	private:
	unsigned m_rows;
	unsigned m_cols;
	T ** m_numbers;
};
#endif
