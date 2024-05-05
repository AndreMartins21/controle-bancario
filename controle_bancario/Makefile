# Makefile

# Variáveis
CXX = g++
CXXFLAGS = -std=c++11

# Arquivos fonte
SRCS = main.cpp Banco.cpp ContaBancaria.cpp

# Arquivo executável
TARGET = banco.out

# Regra de construção do executável
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regra para limpar arquivos temporários e o executável
clean:
	rm -f $(TARGET)
