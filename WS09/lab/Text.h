#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
namespace seneca {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);


      void read();
      virtual void write(std::ostream& os)const;
   };
}
#endif // !SENECA_PERSON_H__

