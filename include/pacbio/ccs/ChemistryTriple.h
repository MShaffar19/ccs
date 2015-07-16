// Copyright (c) 2014-2015, Pacific Biosciences of California, Inc.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted (subject to the limitations in the
// disclaimer below) provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
//  * Neither the name of Pacific Biosciences nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
// GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY PACIFIC
// BIOSCIENCES AND ITS CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL PACIFIC BIOSCIENCES OR ITS
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

// Author: Lance Hepler

#pragma once

#include <string>

namespace PacBio {
namespace CCS {

class ChemistryTriple
{
public:
    unsigned BindingKit;
    unsigned SequencingKit;
    unsigned MajorVersion;
    unsigned MinorVersion;

    ChemistryTriple()
        : BindingKit{0}
        , SequencingKit{0}
        , MajorVersion{0}
        , MinorVersion{0}
    {}

    ChemistryTriple(const std::string& bindingKit,
                    const std::string& sequencingKit,
                    const std::string& changeListID);

    static ChemistryTriple Null()
    {
        return ChemistryTriple();
    }

    bool IsNull() const
    {
        return BindingKit == 0 and SequencingKit == 0 and MajorVersion == 0 and MinorVersion == 0;
    }

    void SetNull()
    {
        BindingKit = 0;
        SequencingKit = 0;
        MajorVersion = 0;
        MinorVersion = 0;
    }

    bool SetValues(const std::string& bindingKit,
                   const std::string& sequencingKit,
                   const std::string& changeListID);
};

} // namespace CCS
} // namespace PacBio
