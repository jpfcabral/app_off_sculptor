#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
};

class Sculptor {
protected:
  Voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  /**
   * @brief Sculptor Construtor da classe Sculptor
   * @param _nx Quantidade de voxels alocados em x
   * @param _ny Quantidade de voxels alocados em y
   * @param _nz Quantidade de voxels alocados em z
   */
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();

  /**
   * @brief setColor escolhe uma cor para desenhar
   * @param r cor vermelha
   * @param g cor verde
   * @param b cor azul
   * @param alpha opacidade
   */
  void setColor(float r, float g, float b, float alpha);

  /**
   * @brief putVoxel Coloca um voxel na posição desejada
   * @param x posição em x
   * @param y posição em y
   * @param z posição em z
   */
  void putVoxel(int x, int y, int z);

  /**
   * @brief cutVoxel Desabilita um voxel
   * @param x posição em x
   * @param y posição em y
   * @param z posição em z
   */
  void cutVoxel(int x, int y, int z);

  /**
   * @brief writeOFF Escreve em um arquivo padrão OFF
   * @param filename Nome do arquivo
   */
  void writeOFF(char* filename);

  Voxel getVoxelState(int x, int y, int z);
};

#endif // SCULPTOR_H
