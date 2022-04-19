package nemu
import spinal.core._
class register_file extends Component{
    val io =new Bundle{
        val writeValid=in Bool()
        val writeAddress=in UInt(5 bits)
        val writeData=in Bits(64 bits)
        
        // val readValid_2=in Bool()
        // val readAddress_2=in UInt(5 bits)
        // val readData_2=out Bits(64 bits)
        
        val readValid_1=in Bool()
        val readAddress_1=in UInt(5 bits)
        val readData_1=out Bits(64 bits)
    }
    noIoPrefix()
    val mem = Mem(Bits(64 bits), wordCount = 32)
mem.write(
  enable  = io.writeValid,
  address = io.writeAddress,
  data    = io.writeData
)
// io.readData_2 := mem.readSync(
//   enable  = io.readValid_2,
//   address = io.readAddress_2
// )
    
    io.readData_1 := mem.readSync(
  enable  = io.readValid_1,
  address = io.readAddress_1
)
}