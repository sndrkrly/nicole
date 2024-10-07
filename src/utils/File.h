#ifndef FILE_H
#define FILE_H

#include <string>

#include <fstream>
#include <sstream>

#include <format>
#include <filesystem>

inline auto ReadFileFromPath( const std::string_view path ) -> const std::string
{
    constexpr auto read_size = std::size_t( 4096 );
    auto stream = std::ifstream( path.data( ) );

    stream.exceptions( std::ios_base::badbit );

    auto out = std::string( );
    auto buf = std::string( read_size, '\00' );

    while (stream.read( &buf[ 0 ], read_size ) )
    {
        out.append( buf, 0, stream.gcount( ) );
    }

    out.append( buf, 0, stream.gcount( ) );
    return out;
}

#endif /* !FILE_H */
