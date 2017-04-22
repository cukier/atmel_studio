using Modbus.Device;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Diagnostics;

namespace Datalogger
{
    class Program
    {
        private static SerialPort port;
        private static ModbusSerialMaster mstr;
        private static long timestam1, timestamp2;
        private static ushort pageSize;
        private static ushort pageNumbers;

        static void Main(string[] args)
        {
            ushort[] resp;
            ushort m_page;

            pageSize = 4;
            pageNumbers = 1;

            port = new SerialPort();
            port.PortName = "COM1";
            port.BaudRate = 9600;
            port.DataBits = 8;
            port.StopBits = StopBits.One;
            port.Parity = Parity.None;
            port.ReadTimeout = 500;
            port.WriteTimeout = 100;

            mstr = ModbusSerialMaster.CreateRtu(port);

            while (true)
            {
                try
                {
                    if (!port.IsOpen)
                    {
                        port.Open();
                        Console.WriteLine("\n\nPorta Aberta");
                    }

                    
                    timestam1 = 0;
                    timestamp2 = 0;
                    Console.WriteLine("Leitura do endereco 0");
                    timestam1 = DateTime.Now.Millisecond;
                    resp = mstr.ReadHoldingRegisters(1, 0, pageSize);
                    timestamp2 = DateTime.Now.Millisecond;
                    Console.WriteLine(GetCal(resp));

                    m_page = resp[3];
                    resp = null;
                    Console.WriteLine("Leitura do endereco " + m_page.ToString());
                    resp = mstr.ReadHoldingRegisters(1, (ushort) (m_page * pageSize), pageSize);
                    Console.WriteLine(GetCal(resp));

                    String str;

                    if (timestamp2 >= timestam1)
                    {
                        str = (timestamp2 - timestam1).ToString();
                    }
                    else
                    {
                        str = ((timestamp2 + 1000) - timestam1).ToString();
                    }

                    Console.WriteLine("Tempo: " + str + "ms");
                }

                catch (Exception ex)
                {
                    Console.WriteLine(ex.ToString());
                }

                finally
                {
                    if (port.IsOpen)
                    {
                        port.Close();
                        Console.WriteLine("Porta Fechada");
                    }
                }

                //System.Threading.Thread.Sleep(5000);
            }
        }

        private static ushort swp(ushort val)
        {
            int aux;

            aux = 0;
            aux = (val & 0xFF00) >> 8;
            aux |= (val & 0xFF) << 8;

            return (ushort)aux;
        }

        private static String GetCal(ushort[] arr)
        {
            String ret;

            ret = ((arr[0] & 0xFF00) >> 8).ToString() + ":";
            ret += (arr[0] & 0xFF).ToString() + ":";
            ret += ((arr[1] & 0xFF00) >> 8).ToString() + " ";
            ret += (arr[1] & 0xFF).ToString() + "/";
            ret += ((arr[2] & 0xFF00) >> 8).ToString() + "/";
            ret += (arr[2] & 0xFF).ToString() + " ";
            ret += arr[3].ToString();

            return ret;
        }
    }
}