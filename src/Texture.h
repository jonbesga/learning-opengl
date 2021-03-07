class Texture {
public:
  unsigned int id;
  Texture(char const* filepath, bool flip = false, bool hasAlpha = false);
  void bind();
  void unBind();
};